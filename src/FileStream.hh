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
        $this->handle->setFlags(SplFileObject::READ_AHEAD);
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

    public function read(int $length) : Chunk
    {
        $content = $this->handle->fread($length);
        $chunk = Chunk::fromString($content);
        $this->updateReadedSize($chunk);

        return $chunk;
    }

    public function readLine() : Chunk
    {
        $content = $this->handle->fgets();
        $chunk = Chunk::fromString($content);
        $this->updateReadedSize($chunk);

        return $chunk;
    }

    public function lines() : LineStream
    {
        while ($this->handle->eof() === false) {
            $chunk = $this->readLine();

            if ($chunk->isEmpty()) {
                break;
            }
            yield $chunk;
        }
    }

    public function bytes(int $length) : ByteStream
    {
        while ($this->handle->eof() === false) {
            $chunk = $this->read($length);

            if ($chunk->isEmpty()) {
                break;
            }
            yield $chunk;
        }
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

    private function updateReadedSize(Chunk $chunk) : void
    {
        $this->readedLength += $chunk->length();

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
