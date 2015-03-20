<?hh //strict

namespace bookman\reader;

class ReadedChunk implements ReadedResult
{

    use Chunk;

    public function __construct (
        private string $content
    )
    {
    }

}
