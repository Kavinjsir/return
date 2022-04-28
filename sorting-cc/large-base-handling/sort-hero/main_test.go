package main

import "testing"

func BenchmarkStuff(b *testing.B) {
	prepareTestData(ChunkNum, ChunkSize, Asset, Input)
	b.ResetTimer()

	for i := 0; i < b.N; i++ {
		externalSort()
	}
}
