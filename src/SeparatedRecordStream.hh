<?hh //strict

/**
 * This file is part of hhpack\file package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\File;

final class SeparatedRecordStream
  implements KeyedIterator<int, SeparatedRecord> {

  private ParsedChunkStream<SeparatedRecord> $stream;

  public function __construct(LineStream $stream, ColumnSpecification $spec) {
    $this->stream = new ParsedChunkStream($stream, $spec);
  }

  public function key(): int {
    return $this->stream->key();
  }

  public function current(): SeparatedRecord {
    return $this->stream->current();
  }

  public function next(): void {
    $this->stream->next();
  }

  public function rewind(): void {
    $this->stream->rewind();
  }

  public function valid(): bool {
    return $this->stream->valid();
  }

}
