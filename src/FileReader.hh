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

    private File $file;
    private FileStream $stream;

    public function __construct(File $file)
    {
//        echo 'DDDDDDDDDDDDDD';
  //      var_dump($file->exists());
    //    echo 'DDDDDDDDDDDDDD';

      //  if ($file->exists() === false) {
        //    throw new FileNotFoundException("File {$file->getPath()} can not be found");
//        }
        $this->file = $file;
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

    public function readBytes(int $length) : Generator<int, ReadedChunk, void>
    {
        return $this->stream->readBytes($length);
    }

    public function readRecords() : Generator<int, ReadedRecord, void>
    {
        return $this->stream->readRecords();
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
