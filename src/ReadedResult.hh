<?hh //strict

namespace bookman\reader;

interface ReadedResult
{
    public function length() : int;
    public function value() : string;
    public function substring(int $startAt, int $length) : string;
    public function match(string $pattern) : bool;
    public function split(string $keyword) : array<string>;
    public function sendTo(ReadedResultReceiver $receiver) : void;
}
