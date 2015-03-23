<?hh //strict

/**
 * This file is part of minimalist\file package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace minimalist\file;



final class FileReader
{

    private File $file;

    public function __construct(File $file)
    {
        $this->file = $file;
    }

    public static function fromString(string $filePath) : FileReader
    {
        return new self(new File($filePath));
    }

    public static function fromFile(File $file) : FileReader
    {
        return new self($file);
    }

    public function readBytes(int $length) : Continuation<ReadedChunk>
    {
        while ($this->file->eof() === false) {
            $readedChunk = $this->file->readBytes($length);
            yield $readedChunk;
        }
    }

    public function readRecords() : Continuation<ReadedRecord>
    {
        while ($this->file->eof() === false) {
            $readedRecord = $this->file->readRecord();
            yield $readedRecord;
        }
    }

    public function readedLength() : int
    {
        return 0;
    }

    public function close() : void
    {
    }

    public function destroy() : void
    {
    }

}
