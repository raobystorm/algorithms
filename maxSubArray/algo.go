package maxsubarray

func maxSubArray(n []int) int {
    prev := n[0]
    max := -101
    for i := 1; i < len(n); i++ {
        if n[i] > 0 {
            // When current is positive
            if prev > 0 {
                prev += n[i]
            } else {
                prev = n[i]
            }
        } else if n[i] < 0 {
            if prev > max {
                max = prev
			}
			if prev + n[i] > 0 {
                // if a small negtive, accept it
				prev += n[i]
			} else {
                // else prev should be negtive
				prev = n[i]
			}
        } else {
            // When 0 consider prev < 0
			if prev < 0 {
				prev = 0
			}
		}
    }
    if prev > max {
        max = prev
    }
    return max
}