<?hh //strict

namespace HHPack\File\Test;

use HHPack\File\Chunk;
use HackPack\HackUnit\Contract\Assert;

final class ChunkTest
{
    <<Test>>
    public function create(Assert $assert) : void
    {
        $chunk = new Chunk('hello');

        $assert->int($chunk->length())->eq(5);
        $assert->string($chunk->value())->is('hello');
    }

    <<Test>>
    public function substring(Assert $assert) : void
    {
        $chunk = new Chunk('hello');
        $assert->string($chunk->substring(0, 3))->is('hel');
    }

    <<Test>>
    public function match(Assert $assert) : void
    {
        $chunk = new Chunk('hello');

        $assert->bool($chunk->match('/^hel/'))->is(true);
        $assert->bool($chunk->match('/foo/'))->is(false);
    }

    <<Test>>
    public function split(Assert $assert) : void
    {
        $chunk = new Chunk('hello');
        $values = $chunk->split('e');

        $assert->int(count($values))->eq(2);
    }
}
