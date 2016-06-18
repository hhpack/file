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

final class ParsedFileReader<T>
{

    public function __construct(
        private FileReader $reader,
        private ParseSpecification<T> $spec
    )
    {
    }

    public function records() : Iterator<T>
    {
        foreach ($this->reader->lines() as $line) {
            yield $this->spec->parse($line);
        }
    }

    public function close() : void
    {
        $this->reader->close();
    }

}
