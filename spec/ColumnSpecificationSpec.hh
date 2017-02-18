<?hh //partial

use HHPack\File\Chunk;
use HHPack\File\ColumnSpecification;

describe(ColumnSpecification::class, function() {
  beforeEach(function() {
    $spec = new ColumnSpecification();
    $spec->addColumn(0, 'name');
    $spec->addColumn(1, 'title');

    $this->spec = $spec;
    $this->record = new Chunk('"foo","bar \" bar"');
  });
  describe('#parse()', function() {
    it('return minimalist\file\reader\SeparatedRecord ', function() {
      $result = $this->spec->parse($this->record);
      expect($result->get('name'))->toBe('foo');
      expect($result->get('title'))->toBe('bar \" bar');
    });
  });
});
