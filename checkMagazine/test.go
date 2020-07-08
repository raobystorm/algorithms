package checkmagazine

import (
	"fmt"
)

func CheckMagazine(magazine []string, note []string) {
	magMap := make(map[string]int)

	for _, word := range magazine {
		magMap[word] += 1
	}
	for _, word := range note {
		if _, ok := magMap[word]; !ok {
			fmt.Println("No")
			return
		}
		magMap[word] -= 1
		if magMap[word] < 0 {
			fmt.Println("No")
			return
		}
	}

	fmt.Println("Yes")
}
