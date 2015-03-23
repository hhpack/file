<?hh //strict

namespace minimalist\file;


final class FileReader
{

    private ?File $file;

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
    }

    public function readBytes(int $length) : Continuation<ReadedChunk>
    {
    }

    public function readRecords() : Continuation<ReadedRecord>
    {
    }

    public function readedLength() : int
    {
    }

    public function close() : void
    {
    }

    public function destroy() : void
    {
    }

}
