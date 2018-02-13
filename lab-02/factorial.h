#pragma once

template <int N>
int fact()
{
    return N * fact<N - 1>();
}

template <>
int fact<0>()
{
    return 1;
}