<?hh //strict

/**
 * This file is part of hhpack\file package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\file;

final class SeparatedStream implements KeyedIterator<int, SeparatedRecord>
{

    private ParsedStream<SeparatedRecord> $stream;

    public function __construct(
        KeyedIterator<int, Chunk> $stream,
        ColumnSpecification $spec
    )
    {
        $this->stream = new ParsedStream($stream, $spec);
    }

    public function key(): int
    {
        return $this->stream->key();
    }

    public function current(): SeparatedRecord
    {
        return $this->stream->current();
    }

    public function next(): void
    {
        $this->stream->next();
    }

    public function rewind(): void
    {
        $this->stream->rewind();
    }

    public function valid(): bool
    {
        return $this->stream->valid();
    }

}
