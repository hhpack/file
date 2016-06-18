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

final class ParsedChunkStream<T> implements KeyedIterator<int, T>
{

    public function __construct(
        private KeyedIterator<int, Chunk> $stream,
        private ParseSpecification<T> $spec
    )
    {
    }

    public function key(): int
    {
        return $this->stream->key();
    }

    public function current(): T
    {
        $chunk = $this->stream->current();
        return $this->spec->parse($chunk);
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
