<?hh //partial

use hhpack\file\File;
use hhpack\file\FileReader;
use hhpack\file\ColumnSpecification;
use hhpack\file\SeparatedFileReader;


describe(SeparatedFileReader::class, function() {
  beforeEach(function() {
    $spec = new ColumnSpecification();
    $spec->addColumn(0, 'name');
    $spec->addColumn(1, 'title');

    $this->spec = $spec;
    $this->fileReader = FileReader::fromString(realpath(__DIR__ . '/fixtures/text.csv'));
    $this->reader = new SeparatedFileReader($this->fileReader, $this->spec);
  });
  describe('#fromString()', function() {
    it('return file reader', function() {
      expect($this->reader)->toBeAnInstanceOf(SeparatedFileReader::class);
    });
  });
  describe('#records()', function() {
    beforeEach(function() {
      $concatValue = '';
      $records = $this->reader->records();

      foreach ($records as $record) {
        $concatValue .= (string) $record->get('name');
        $concatValue .= (string) $record->get('title');
      }
      $this->concatValue = $concatValue;
    });
    it('return Iterator<SeparatedRecord>', function() {
      expect($this->concatValue)->toBe("foo1bar1foo2bar2");
    });
  });
});
