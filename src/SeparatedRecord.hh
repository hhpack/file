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

use \ConstCollection;


class SeparatedRecord implements ConstCollection<Pair<string, string>>
{

    private ImmMap<string, string> $map;

    public function __construct(KeyedIterator<string, string> $values)
    {
        $this->map = new ImmMap($values);
    }

    public function get(string $label) : string
    {
        return $this->map->at($label);
    }

    public function count() : int
    {
        return $this->map->count();
    }

    public function isEmpty() : bool
    {
        return $this->map->isEmpty();
    }

    public function items() : Iterable<Pair<string, string>>
    {
        return $this->map->items();
    }

}
