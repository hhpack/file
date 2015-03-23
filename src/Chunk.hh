<?hh //strict

namespace minimalist\file;


class Chunk implements ReadedResult
{

    public function __construct (
        private string $content
    )
    {
    }

    public function length() : int
    {
        return strlen($this->content);
    }

    public function value() : string
    {
        return $this->content;
    }

    public function substring(int $startAt, int $length) : string
    {
        return substr($this->content, $startAt, $length);
    }

    public function match(string $pattern) : bool
    {
        return preg_match($pattern, $this->content) === 1;
    }

    public function split(string $keyword) : array<string>
    {
        return explode($keyword, $this->content);
    }

    public function sendTo(ReadedResultReceiver $receiver) : void
    {
        $receiver->receiveResult($this);
    }

}
