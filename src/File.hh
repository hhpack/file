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

use \SplFileInfo;
use \SplFileObject;
use \RuntimeException;


final class File
{

    private SplFileInfo $stat;
    private ?SplFileObject $file;
    private bool $opended = false;


    public function __construct(string $filePath)
    {
        $this->stat = new SplFileInfo($filePath);
    }

    public function open(FileMode $mode) : void
    {
        try {
            $this->file = $this->stat->openFile((string) $mode);
        } catch (RuntimeException $exception) {
            throw new IOException($exception->getMessage(), $exception->getCode(), $exception);
        }
        $this->file->setFlags(
            SplFileObject::SKIP_EMPTY |
            SplFileObject::DROP_NEW_LINE |
            SplFileObject::READ_AHEAD
        );
        $this->opended = true;
    }

    public function getName() : string
    {
        return $this->stat->getFilename();
    }

    public function getPath() : string
    {
        return $this->stat->getPathname();
    }

    public static function fromString(string $filePath) : File
    {
        return new self($filePath);
    }

    public function readBytes(int $length) : ?ReadedChunk
    {
        $content = $this->file->fread($length);
        if ($content === false) {
            return null;
        }
        return new Chunk($content);
    }

    public function readRecord() : ?ReadedRecord
    {
        $content = $this->file->fgets();
        if ($content === false) {
            return null;
        }
        return new Chunk($content);
    }

    public function isOpened() : bool
    {
        return $this->opended;
    }

    public function eof() : bool
    {
        return $this->file->eof();
    }

    public function size() : int
    {
        return $this->stat->getSize();
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
