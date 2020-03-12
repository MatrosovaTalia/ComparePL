class AlgorithmResults:
	def __init__(self, algorithm):
		self.algorithm = algorithm

		self.fields = {}
		self.languages = []

	def addResult(self, language, field_name, field_id, value):
		if (not field_id in self.fields.keys()):
			self.fields[field_id] = {
				'desc': field_name,
				'values': {}
			}
		self.fields[field_id]['values'][language] = {
			'value': value
		}
		if not language in self.languages:
			self.languages.append(language)

	def printResults(self):
		print('# ', self.algorithm, '\n')

		print('| Metric | ', end='')
		for lang in self.languages:
			print(lang, '| ', end='')
		print('\n| - | ', end='')

		for lang in self.languages:
			print(' - | ', end='')
		print('')

		for _, field in self.fields.items():
			# print(field)
			print('|', field['desc'], '| ', end='')
			for lang in self.languages:
				if lang in field['values'].keys():
					print(field['values'][lang]['value'], ' | ', end='')
				else:
					print('~ | ')
			print('')
		print('')


algos = {}

res_file = "results.txt"
f = open(res_file, 'r')

state = 0
current_lang = ''
current_algo = ''

max_symbols = 6

for line in f.readlines():
	if(line.strip() == '##'):
		state = 1
	else:
		if state == 1:
			current_lang = line.strip()
			state = 2
		elif state == 2:
			if not line.strip() in algos.keys():
				algos[line.strip()] = AlgorithmResults(line.strip())
			current_algo = line.strip()
			state = 3
		elif state == 3:
			algos[current_algo].addResult(current_lang, 'Execution time (ms)', 0, line.strip()[:max_symbols])
			state = 4
		elif state == 4:
			vals = line.strip().split(' ')
			algos[current_algo].addResult(current_lang, 'Max RSS Memory(kb)', 1, vals[0][:max_symbols])
			algos[current_algo].addResult(current_lang, 'Minor (frame) pf', 2, vals[1][:max_symbols])
			algos[current_algo].addResult(current_lang, 'Voluntary con. switches', 3, vals[2][:max_symbols])
			algos[current_algo].addResult(current_lang, 'Involuntary con. switches', 4, vals[3][:max_symbols])
			state = 2

for _,res in algos.items():
	res.printResults()
			
		
			

