<?hh //strict

/**
 * This file is part of hhpack\file package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\file;


use \Generator;
use \SplFileObject;
 
final class FileStream
{

    private File $file;
    private int $readedLength;
    private SplFileObject $handle;
    private bool $opended = false;

    public function __construct(File $file)
    {
        if ($file->exists() === false) {
            throw new FileNotFoundException("File {$file->getPath()} can not be found");
        }
        $this->file = $file;
        $this->readedLength = 0;
        $this->handle = new SplFileObject($file->getPath(), (string) FileMode::READ_ONLY);
        $this->handle->setFlags(
            SplFileObject::SKIP_EMPTY |
            SplFileObject::DROP_NEW_LINE |
            SplFileObject::READ_AHEAD
        );
        $this->opended = true;
    }

    public static function fromString(string $filePath) : this
    {
        return new self(new File($filePath));
    }

    public static function fromFile(File $file) : this
    {
        return new self($file);
    }

    public function readBytes(int $length) : Generator<int, ReadedChunk, void>
    {
        while ($this->handle->eof() === false) {
            $chunk = $this->read($length);

            if ($chunk->isEmpty()) {
                break;
            }

            $readedLength = $chunk->length();
            $this->updateReadedSize($readedLength);
            yield $chunk;
        }
    }

    public function readRecords() : Generator<int, ReadedRecord, void>
    {
        while ($this->eof() === false) {
            $readedRecord = $this->readLine();

            if ($readedRecord->isEmpty()) {
                break;
            }

            $readedLength = $readedRecord->length() + 1;

            $this->updateReadedSize($readedLength);
            yield $readedRecord;
        }
    }

    public function read(int $length) : ReadedChunk {
        $content = $this->handle->fread($length);
        return new Chunk($content);
    }

    public function readLine() : ReadedRecord
    {
        $content = $this->handle->fgets();
        return new Chunk($content);
    }

    public function isOpened() : bool
    {
        return $this->opended;
    }

    public function totalSize() : int
    {
        return $this->file->size();
    }

    public function readedSize() : int
    {
        return $this->readedLength;
    }

    public function close() : void
    {
        $this->opended = false;
    }

    public function eof() : bool
    {
        return $this->handle->eof();
    }

    private function updateReadedSize(int $length) : void
    {
        $this->readedLength += $length;

        if ($this->readedLength < $this->totalSize()) {
            return;
        }

        $this->readedLength = $this->totalSize();
    }

    public function __destruct() : void
    {
        if ($this->opended === false) {
            return;
        }
        $this->close();
    }

}
