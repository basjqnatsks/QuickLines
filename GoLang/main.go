package main

import (
	"fmt"
	"os"
	"time"
)

func main() {
	start := time.Now()
	result, _ := os.ReadFile("words.txt")

	chans := make([]chan int, 0)

	for i := 0; i < 8; i++ {
		chans = append(chans, make(chan int))
	}

	chunk := len(result) / len(chans)

	go readNewLines(result[:chunk], chans[0])
	for i := 1; i < len(chans)-1; i++ {
		go readNewLines(result[i*chunk:(i+1)*chunk], chans[i])
	}
	go readNewLines(result[(len(chans)-1)*chunk:], chans[len(chans)-1])

	sumChans := 0
	for _, channel := range chans {
		sumChans += <-channel
	}

	end := time.Now()
	fmt.Println(end.Sub(start))
}

func readNewLines(bs []byte, c chan int) {
	result := 0
	for _, byte := range bs {
		if byte == '\n' {
			result++
		}
	}
	c <- result
}
