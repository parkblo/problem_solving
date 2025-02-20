while True:
	try:
		a,b = input().split()
		t_idx = 0
		result = True
		for i in a:
			flag = False
			for j in range(t_idx,len(b)):
				if i == b[j]:
					t_idx = j+1
					flag = True
					break
			if flag is False:
				result = False
				break

		if result:
			print("Yes")
		else:
			print("No")
	except:
		break
