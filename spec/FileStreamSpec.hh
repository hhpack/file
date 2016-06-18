<?hh //partial

use hhpack\file\FileStream;

describe(FileStream::class, function() {
  beforeEach(function() {
    $this->path = realpath(__DIR__ . '/fixtures/text.log');
    $this->stream = FileStream::fromString($this->path);
  });
  describe('#readLine()', function() {
    it('return readed line string', function() {
      $chunk = $this->stream->readLine();
      expect($chunk->value())->toEqual('1,foo');
    });
  });
  describe('#lines()', function() {
    it('return line stream', function() {
      $lineCount = 0;
      $lines = $this->stream->lines();

      foreach ($lines as $line) {
        $lineCount++;
      }
      expect($lineCount)->toEqual(4);
    });
  });
});
