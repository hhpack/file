<?hh //strict

/**
 * This file is part of hhpack\file package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\File;

final class ColumnSpecification
  implements ParseSpecification<SeparatedRecord> {

  private Map<int, string> $map;

  public function __construct(
    private string $delimiter = ',',
    private string $enclosure = '"',
    private string $escape = '\\',
  ) {
    $this->map = Map {};
  }

  public function addColumn(int $index, string $label): void {
    $this->map->set($index, $label);
  }

  public function parse(Chunk $record): SeparatedRecord {
    $values = str_getcsv(
      (string) $record,
      $this->delimiter,
      $this->enclosure,
      $this->escape,
    );

    $result = Map {};
    $vector = new Vector($values);

    foreach ($vector->getIterator() as $index => $value) {
      if ($value === null) {
        $value = '';
      }

      if ($this->map->containsKey($index) === false) {
        //oops!!
      }
      $label = $this->map->at($index);
      $result->set($label, $value);
    }

    return new SeparatedRecord($result->getIterator());
  }

}
