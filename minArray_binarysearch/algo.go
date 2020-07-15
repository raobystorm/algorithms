func minInOrder(n []int, idx1 int, idx2 int) int {
    res := n[idx1]
    for i := idx1+1; i <= idx2; i++ {
        if res > n[i] {
            res = n[i]
        }
    }
    return res
}

// Binary search to find spin point
func minArray(n []int) int {
    idx1 := 0
    idx2 := len(n)-1
    idxMid := idx1
    for n[idx1] >= n[idx2] {
        if idx2 - idx1 == 1 {
            idxMid = idx2
            break
        }

        idxMid = (idx1 + idx2) / 2
        if n[idx1] == n[idx2] && n[idxMid] == n[idx1] {
            // If n[idx1] == n[idx2] == n[idxMid], e.g. 2 2 2 1 2 2 2
            // then find one by one
            return minInOrder(n, idx1, idx2)
        }

        if n[idxMid] >= n[idx1] {
            idx1 = idxMid
        } else if n[idxMid] <= n[idx2] {
            idx2 = idxMid
        }
    }

    return n[idxMid]
}