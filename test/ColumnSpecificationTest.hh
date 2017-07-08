<?hh //strict

namespace HHPack\File\Test;

use HHPack\File\Chunk;
use HHPack\File\ColumnSpecification;
use HackPack\HackUnit\Contract\Assert;

final class ColumnSpecificationTest
{
    <<Test>>
    public function create(Assert $assert) : void
    {
        $spec = new ColumnSpecification();
        $spec->addColumn(0, 'name');
        $spec->addColumn(1, 'title');

        $record = new Chunk('"foo","bar \" bar"');
        $result = $spec->parse($record);

        $assert->string($result->get('name'))->is('foo');
        $assert->string($result->get('title'))->is('bar \" bar');
    }
}
