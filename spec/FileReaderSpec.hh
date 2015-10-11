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
  describe('#bytes()', function() {
    beforeEach(function() {
      $concatValue = '';
      $chunkValues = $this->reader->bytes(6);

      foreach ($chunkValues as $chunkValue) {
        $concatValue .= (string) $chunkValue;
      }
      $this->concatValue = $concatValue;
    });
    it('return byte stream', function() {
      expect($this->concatValue)->toBe("1,foo2,bar3,foo4,bar");
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
  describe('#readedSize()', function() {
    beforeEach(function() {
      $progressSizes = [];
      $lines = $this->reader->lines();

      foreach ($lines as $line) {
        $progressSizes[] = $this->reader->readedSize();
      }
      $progressSizes[] = $this->reader->readedSize();
      $this->progressSizes = $progressSizes;
    });
    it('return readed byte size', function() {
      expect($this->progressSizes[0])->toBe(6);
      expect($this->progressSizes[1])->toBe(12);
      expect($this->progressSizes[2])->toBe(18);
      expect($this->progressSizes[3])->toBe(24);
      expect($this->progressSizes[4])->toBe($this->reader->totalSize());
    });
  });
});
