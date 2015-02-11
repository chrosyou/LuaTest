
iRet = 10;
iRowTotal = 0;

function showrow1(udata,cols,values,names)
	iRowTotal = iRowTotal +  1;
	assert(udata=='test_udata');
	iRet = cols;
	for i=1,cols do 
		--print('',names[i],values[i]);
	end
	return 0
end

function add(x,y)
	os.remove('test.db');
	local test = lsqlite3.open('test.db');
	--local tnrows = test:exec([[select * from City]]);
	
	sql=[=[
		CREATE TABLE numbers(num1,num2,str);
		INSERT INTO numbers VALUES(1,11,"ABC");
		INSERT INTO numbers VALUES(2,22,"DEF");
		INSERT INTO numbers VALUES(2,33,"UVW");
		INSERT INTO numbers VALUES(4,44,"UVW");
	]=]
	-- function showrow(udata,cols,values,names)
		-- assert(udata=='test_udata')
		-- print('exec:')
		-- print("rows:", cols);
		-- for i=1,cols do 
			-- print('',names[i],values[i]);
		-- end
		-- return 0
	-- end
	iExeRet = test:exec(sql);
	
	-- sql=[[
          -- select * from City;
        -- ]]
	
	-- local iExeRet = test:execute(sql,showrow1,'test_udata1');
	-- print(test:errmsg());
	-- local t = test:nrows("SELECT * FROM City");
	-- print(type(t));
	
	
	--var表示执行sql语句后获得每一行的内容
	--rows 返回的数据集的列名 沿用数据
	-- for Name1 in test:urows("SELECT * FROM City where Population > 12700 and Population < 19000") do
		-- print(Name);
	-- end
	
	
	--prepare函数集
	local lp = test:prepare("SELECT * FROM City");
	
	local name = lp:bind(1, "");
	-- print(name);
	

	
	test:close();
	return 0;
end