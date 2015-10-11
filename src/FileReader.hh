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

final class FileReader
{

    private FileStream $stream;

    public function __construct(File $file)
    {
        $this->stream = FileStream::fromFile($file);
    }

    public static function fromString(string $filePath) : FileReader
    {
        return new self(new File($filePath));
    }

    public static function fromFile(File $file) : FileReader
    {
        return new self($file);
    }

    public function bytes(int $length) : ByteStream
    {
        return $this->stream->bytes($length);
    }

    public function lines() : LineStream
    {
        return $this->stream->lines();
    }

    public function totalSize() : int
    {
        return $this->stream->totalSize();
    }

    public function readedSize() : int
    {
        return $this->stream->readedSize();
    }

    public function close() : void
    {
        $this->stream->close();
    }

}
