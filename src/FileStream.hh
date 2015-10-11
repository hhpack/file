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
use \Exception;

final class FileStream
{

    private File $file;
    private SplFileObject $handle;
    private bool $opended = false;

    public function __construct(File $file)
    {
        if ($file->exists() === false) {
            throw new FileNotFoundException("File {$file->getPath()} can not be found");
        }
        $this->file = $file;
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
        // Cast to a string for when this method returns false
        // Because this would type check error.
        $content = (string) $this->handle->fread($length);
        return Chunk::fromString($content);
    }

    public function readLine() : Chunk
    {
        // Cast to a string for when this method returns false
        // Because this would type check error.
        $content = (string) $this->handle->fgets();
        return Chunk::fromString($content);
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

    public function close() : void
    {
        $this->opended = false;
    }

    public function eof() : bool
    {
        return $this->handle->eof();
    }

    public function __destruct() : void
    {
        if ($this->opended === false) {
            return;
        }
        $this->close();
    }

}
