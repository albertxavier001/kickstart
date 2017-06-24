
def test(numOfOne, target, base):
	cur = 1
	ans = 0
	for i in xrange(numOfOne):
		ans = ans + cur
		cur = cur * base
		if ans > target:
			return 1
	if ans > target:
		return 1
	if ans < target:
		return -1
	return 0

# print test(2, 13, 12)
text = ""

T = int(raw_input())
for cas in xrange(T):
	N = int(raw_input())
	i = 64
	ans = -1
	while i >= 2:
		left = 2
		right = N - 1
		while left <= right:
			mid = (left + right) >> 1
			testres = test(i, N, mid)
			if testres > 0:
				right = mid - 1
			elif testres < 0:
				left = mid + 1
			else:
				ans = mid
				break
		if ans != -1:
			break
		i = i - 1
	print "Case #" + str(cas + 1) + ": " + str(ans)
	text += "Case #" + str(cas + 1) + ": " + str(ans) + "\n"

with open("ouput_py.txt", "w") as f:
	f.write(text)