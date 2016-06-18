<?hh //partial

use hhpack\file\File;
use hhpack\file\FileReader;
use hhpack\file\FileNotFoundException;

describe(FileReader::class, function() {
  beforeEach(function() {
    $this->path = realpath(__DIR__ . '/fixtures/text.log');
    $this->reader = FileReader::fromString($this->path);
  });
  describe('#__construct()', function() {
    context('when file not exists', function() {
      it('throw FileNotFoundException', function() {
        expect(function() {
          FileReader::fromString('not_found.txt');
        })->toThrow(FileNotFoundException::class);
      });
    });
  });
  describe('#fromString()', function() {
    it('return file reader', function() {
      expect($this->reader)->toBeAnInstanceOf(FileReader::class);
    });
  });
  describe('#lines()', function() {
    beforeEach(function() {
      $concatValue = '';
      $lines = $this->reader->lines();

      foreach ($lines as $line) {
        $concatValue .= (string) $line;
      }
      $this->concatValue = $concatValue;
    });
    it('return line stream', function() {
      expect($this->concatValue)->toBe("1,foo2,bar3,foo4,bar");
    });
  });
});
