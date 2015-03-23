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

use \SplFileObject;


final class File
{

    private ?SplFileObject $file;
    private bool $opended = false;

    public function __construct(string $filePath)
    {
        if (file_exists($filePath) === false) {
            throw new FileNotFoundException("File {$filePath} can not be found");
        }

        if (is_readable($filePath) === false) {
            throw new UnreadbleFileException("File {$filePath} is not a readable");
        }

        $this->file = new SplFileObject($filePath, 'r');
        $this->file->setFlags(SplFileObject::DROP_NEW_LINE);
        $this->opended = true;
    }

    public function getName() : string
    {
        return $this->file->getFilename();
    }

    public function getPath() : string
    {
        return $this->file->getPathname();
    }

    public static function fromString(string $filePath) : File
    {
        return new self($filePath);
    }

    public function readBytes(int $length) : ReadedChunk
    {
        $content = $this->file->fread($length);
        return new Chunk($content);
    }

    public function readRecord() : ReadedRecord
    {
        $content = $this->file->fgets();
        return new Chunk($content);
    }

    public function eof() : bool
    {
        return $this->file->eof();
    }

    public function size() : int
    {
        return $this->file->getSize();
    }

    public function exists() : bool
    {
        return file_exists($this->getPath());
    }

    public function close() : void
    {
        $this->file = null;
        $this->opended = false;
    }

    public function __destruct() : void
    {
        if ($this->opended === false) {
            return;
        }
        $this->close();
    }

}
