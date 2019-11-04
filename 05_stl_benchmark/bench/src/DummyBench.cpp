#include "Dummy.h"
#include "BenchIncludes.h"

static void Dummy_Integrate(State& state) {

    Dummy dummy{};

    for (auto _ : state) {

        auto integral = dummy.integrate(0, state.range(0)); //i tu bedziemy cos liczyc i benchmark to sobie policzy ile zeszlo itd..

        DoNotOptimize(integral);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK(Dummy_Integrate)->RangeMultiplier(2)->Range(1<<5, 1<<18)->Complexity();
//to zakres w jakim benchmark sie odpala. Zaczynamy od 2 i lecimy potegami 2