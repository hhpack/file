<?hh //strict

namespace HHPack\File\Test;

use HHPack\File\File;
use HHPack\File\FileLineStream;
use HHPack\File\ColumnSpecification;
use HHPack\File\SeparatedRecordStream;
use HackPack\HackUnit\Contract\Assert;

final class SeparatedRecordStreamTest
{
    <<Test>>
    public function create(Assert $assert) : void
    {
        $spec = new ColumnSpecification();
        $spec->addColumn(0, 'name');
        $spec->addColumn(1, 'title');

        $linesStream = FileLineStream::fromString(realpath(__DIR__ . '/fixtures/text.csv'));
        $stream = new SeparatedRecordStream($linesStream, $spec);
        $concatValue = "";

        while($stream->valid()) {
            $record = $stream->current();
            $concatValue .= (string) $record->get('name');
            $concatValue .= (string) $record->get('title');
            $stream->next();
        }

        $assert->string($concatValue)->is('foo1bar1foo2bar2');
    }
}
