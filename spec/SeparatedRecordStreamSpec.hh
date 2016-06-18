<?hh //partial

use hhpack\file\File;
use hhpack\file\FileLineStream;
use hhpack\file\ColumnSpecification;
use hhpack\file\SeparatedRecordStream;


describe(SeparatedRecordStream::class, function() {
  beforeEach(function() {
    $spec = new ColumnSpecification();
    $spec->addColumn(0, 'name');
    $spec->addColumn(1, 'title');

    $stream = FileLineStream::fromString(realpath(__DIR__ . '/fixtures/text.csv'));

    $this->stream = new SeparatedRecordStream($stream, $spec);
  });
  describe('#next()', function() {
    beforeEach(function() {
      $concatValue = '';

      while($this->stream->valid()) {
        $record = $this->stream->current();
        $concatValue .= (string) $record->get('name');
        $concatValue .= (string) $record->get('title');
        $this->stream->next();
      }
      $this->concatValue = $concatValue;
    });
    it('move to next element', function() {
      expect($this->concatValue)->toBe("foo1bar1foo2bar2");
    });
  });
});
