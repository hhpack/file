<?hh //strict

namespace minimalist\file;

//use \Continuation;

//type ReadedChunk = Chunk;
//type ReadedRecord = Chunk;

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
