
local json = require "cjson"

function add(x, y)
	local retTable = {};    --最终产生json的表
	--顺序数值
	local intDatas = {};
	intDatas[1] = 100;
	intDatas[2] = "100";
	--数组
	local aryDatas = {};
	aryDatas[1] = {};
	aryDatas[1]["键11"] = "值11";
	aryDatas[1]["键12"] = "值12";
	aryDatas[2] = {};
	aryDatas[2]["键21"] = "值21";
	aryDatas[2]["键22"] = "值22";
	--对Table赋值
	retTable["键1"] = "值1";
	retTable[2] = 123;
	retTable["int_datas"] = intDatas;
	retTable["aryDatas"] = aryDatas;
	--将表数据编码成json字符串
	local jsonStr = cjson.encode(retTable);
--	local sampleJson = [[{"age":"23","testArray":{"array":[8,9,11,14,25]},"Himi":"himigame.com"}]];
	local file = io.open("a.txt", "a+");
	file:write(jsonStr);
	file:close();
	--local data = cjson.decode(sampleJson);
	return "age";
end