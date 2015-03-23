<?hh //strict

namespace minimalist\file;

class ReadedChunk implements ReadedResult
{

    use Chunk;

    public function __construct (
        private string $content
    )
    {
    }

}
