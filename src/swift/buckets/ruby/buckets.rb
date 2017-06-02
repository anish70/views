require 'pp'

class HistogramReport  
    def self.group_by_last_digit(numbers)
        array  = [0] * 11
        array1 = numbers.select { |num| num < 100 }
        for i in 0..9 do
            bucket = []
            for n in array1 do
               if n.to_s[-1].to_i == i
                  bucket << n 
               end
            end
            array[i] = process_group(bucket)
        end

        array2 = numbers - array1
        unless array2.empty?
            n = 10
            x = process_group(array2)
            array[10] = x
        end
        array
    end

    def self.process_group(group)
        group.inject(0) { |sum, x| sum + x }
    end
end

if __FILE__==$0
  numbers = []
  File.open(ARGV.first).each_line do |l|
    numbers.push(l.chomp.to_i)
  end

  result = HistogramReport.group_by_last_digit(numbers)
  pp(result)
end

