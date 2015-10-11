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

interface ReadedResult
{
    public function length() : int;
    public function value() : string;
    public function substring(int $startAt, int $length) : string;
    public function match(string $pattern) : bool;
    public function split(string $keyword) : array<string>;
    public function sendTo(ReadedResultReceiver $receiver) : void;
}
