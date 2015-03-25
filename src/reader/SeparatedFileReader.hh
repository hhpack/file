<?hh //strict

/**
 * This file is part of minimalist\file package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace minimalist\file\reader;

use minimalist\file\FileReader;
use \Generator;


final class SeparatedFileReader
{

    private FileReader $reader;

    public function __construct(FileReader $reader)
    {
        $this->reader = $reader;
    }

    public static function fromString(string $filePath) : SeparatedFileReader
    {
        $reader = FileReader::fromString($filePath);
        return new self($reader);
    }

    public function readRecords(ColumnSpecification $spec) : Generator<int, SeparatedRecord, void>
    {
        foreach ($this->reader->readRecords() as $readRecord) {
            yield $spec->parse($readRecord);
        }
    }

    public function close() : void
    {
        $this->reader->close();
    }

}
