<?hh //partial

use hhpack\file\FileStream;

describe(FileStream::class, function() {
  beforeEach(function() {
    $this->path = realpath(__DIR__ . '/fixtures/text.log');
    $this->stream = FileStream::fromString($this->path);
  });
  describe('#read()', function() {
    it('return readed byte string', function() {
      $chunk = $this->stream->read(1);
      expect($chunk->value())->toEqual('1');
    });
  });
  describe('#readLine()', function() {
    it('return readed line string', function() {
      $chunk = $this->stream->readLine();
      expect($chunk->value())->toEqual('1,foo');
    });
  });
});
