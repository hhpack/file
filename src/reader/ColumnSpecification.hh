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


use minimalist\file\Chunk;


class ColumnSpecification
{

    private string $delimiter;
    private Map<int, string> $map;

    public function __construct(string $delimiter = ',')
    {
        $this->map = Map {};
        $this->delimiter = $delimiter;
    }

    public function addColumn(int $index, string $label) : void
    {
        $this->map->set($index, $label);
    }

    public function parse(Chunk $record) : SeparatedRecord
    {
        $values = $record->split($this->delimiter);

        $vector = new Vector($values);
        $result = Map {};

        foreach ($vector->getIterator() as $index => $value) {
            if ($this->map->containsKey($index) === false) {
                //oops!!
            }
            $label = $this->map->at($index);
            $result->set($label, $value);
        }

        return new SeparatedRecord( $result->getIterator() );
    }

}
