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

use \SplFileInfo;

final class File
{

    private SplFileInfo $stat;

    public function __construct(string $filePath)
    {
        $this->stat = new SplFileInfo($filePath);
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

    public function size() : int
    {
        return $this->stat->getSize();
    }

    public function exists() : bool
    {
        return file_exists($this->getPath());
    }

}
