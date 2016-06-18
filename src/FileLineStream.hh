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


use \SplFileObject;
use \Exception;

final class FileLineStream implements KeyedIterator<int, Chunk>
{

    private File $file;
    private SplFileObject $handle;
    private LineStream $stream;
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
        $this->stream = $this->lines();
    }

    public function key(): int
    {
        return $this->stream->key();
    }

    public function current(): Chunk
    {
        return $this->stream->current();
    }

    public function next(): void
    {
        $this->stream->next();
    }

    public function rewind(): void
    {
        $this->stream->rewind();
    }

    public function valid(): bool
    {
        return $this->stream->valid();
    }

    public function __destruct() : void
    {
        if ($this->opended === false) {
            return;
        }
        $this->close();
    }

    public static function fromString(string $filePath) : this
    {
        return new self(new File($filePath));
    }

    public static function fromFile(File $file) : this
    {
        return new self($file);
    }

    private function readLine() : Chunk
    {
        // Cast to a string for when this method returns false
        // Because this would type check error.
        $content = (string) $this->handle->fgets();
        return Chunk::fromString($content);
    }

    private function lines() : LineStream
    {
        while ($this->handle->eof() === false) {
            $chunk = $this->readLine();

            if ($chunk->isEmpty()) {
                break;
            }
            yield $chunk;
        }
    }

    private function isOpened() : bool
    {
        return $this->opended;
    }

    private function close() : void
    {
        $this->opended = false;
    }

    private function eof() : bool
    {
        return $this->handle->eof();
    }

}
