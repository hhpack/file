<?hh //strict

namespace minimalist\file;

interface ReadedResultReceiver
{
    public function receiveResult(ReadedResult $result) : void;
}
