require 'minitest/spec'
require 'minitest/autorun'
require './buckets'

def read_data_file(fn)
    File.readlines(fn).map(&:chomp).map(&:to_i)
end

describe HistogramReport do
  it "correctly processes datafile 1" do
    data = read_data_file("input1.dat")
    expected = [450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 6225]
    HistogramReport.group_by_last_digit(data).must_equal expected
  end

  it "correctly processes datafile 2" do
    data = read_data_file("input2.dat")
    expected = [910, 839, 1120, 1014, 1126, 900, 974, 866, 1698, 1384, 10944] 
    HistogramReport.group_by_last_digit(data).must_equal expected
  end

  it "correctly processes the datafile 3" do
    data = read_data_file("input3.dat")
    expected = [0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    HistogramReport.group_by_last_digit(data).must_equal expected
  end
end
