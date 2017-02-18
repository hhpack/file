<?hh //partial

use HHPack\File\File;

describe(File::class, function() {
  beforeEach(function() {
    $this->path = realpath(__DIR__ . '/fixtures/text.log');
    $this->file = File::fromString($this->path);
  });
  describe('#getName()', function() {
    it('return file name', function() {
      expect($this->file->getName())->toEqual('text.log');
    });
  });
  describe('#getPath()', function() {
    it('return file path', function() {
      expect($this->file->getPath())->toEqual($this->path);
    });
  });
  describe('#exists()', function() {
    context('when file exists', function() {
      it('return true', function() {
        expect($this->file->exists())->toBeTrue();
      });
    });
  });
});
