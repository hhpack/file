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
    private int $readedLength;

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
            $readedLength = $readedChunk->length();
            $this->updateReadedSize($readedLength);
            yield $readedChunk;
        }
    }

    public function readRecords() : Continuation<ReadedRecord>
    {
        while ($this->file->eof() === false) {
            $readedRecord = $this->file->readRecord();
            $readedLength = $readedRecord->length() + 1;
            $this->updateReadedSize($readedLength);
            yield $readedRecord;
        }
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
    }

    public function destroy() : void
    {
    }

    private function updateReadedSize(int $length) : void
    {
        $this->readedLength += $length;

        if ($this->readedLength < $this->totalSize()) {
            return;
        }

        $this->readedLength = $this->totalSize();
    }

}
