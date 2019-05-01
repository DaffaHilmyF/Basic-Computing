Program pembuatanRekeningBank;
//uses crt;
const
	gold = 1000000;
	platinum = 2000000;
	nMax = 100;
type
	idn = record
	id : integer;
	nama : string;
	jenisTabungan : string;
	jumlahSetoranAwal : longint;
	biayaAdminBulanan : integer;
	biayaPenarikanlain : integer;
	end;
	nasabah = array[1..nMax] of idn;
var
	i,n, num: integer;
	bank: nasabah;

	procedure tampilan;
	begin
		writeln('Selamat datang di Menu utama Pembuatan Rekening');
		writeln('1. Input data');
		writeln('2. Cari data');
		writeln('3. Sorting data');
		writeln('4. Edit data');
		writeln('5. Outputkan data');
		writeln('6. Keluar');
	end;
	
	procedure pilihan(var i : integer);
	begin
		write('Pilihan Anda : ');
		readln(i);
	end;
	
	function admin(jenis: string;uang: longint):integer;
	begin
		if (jenis = 'GOLD') then
			if(uang >= 3*gold) then
				admin := 0
			else if(uang = 2*gold) then
				admin := 1000
			else
				admin := 2500
		else
			if(uang >= 3*platinum) then
				admin := 0
			else if(uang = 2*platinum) then
				admin := 1000
			else
				admin := 2500;
	end;
	
	procedure olahData(var x: nasabah; pos: integer);
	begin
		x[pos].biayaAdminBulanan := admin(x[pos].jenisTabungan,x[pos].jumlahSetoranAwal);
		x[pos].biayaPenarikanlain := x[pos].biayaAdminBulanan * 5  div 100;
	end;
	
	procedure inputNama(var x: string);
	var
		a : string;
	begin
		write('Masukan Nama : ');
		readln(a);
		while(a ='') do
		begin
			write('Masukan Nama : ');
			readln(a);
		end;
		x :=a;
	end;
	
	procedure inputJenisSetoran(var x: string;var setoran:longint);
	var
		b : boolean;
		uang:longint;
		jenis: string;	
	begin
		write('Masukan Jenis Tabungan : ');
		readln(jenis);
		jenis:= upcase(jenis);
		while not((jenis <> 'GOLD') xor (jenis <> 'PLATINUM')) do
		begin
			writeln('Maaf Jenis Tabungan anda tak tersedia');
			writeln('Maaf Jenis tabungan bukan gold atau platinum');
			write('Masukan Jenis Tabungan : ');
			readln(jenis);
			jenis := upcase(jenis);
		end;
		x := jenis;
		b:= false;
			repeat
			write('Masukan Setoran awal : ');
			readln(uang);
			if(x = 'GOLD') then
				if (uang >= gold) then
					b:= True
				else
					writeln('Setoran awal anda kurang dari 1000000');
			if(x = 'PLATINUM') then
				if (uang >= platinum) then
					b:= True
				else
					writeln('Setoran awal anda kurang dari 2000000');
			until (b);
		setoran:= uang;
	end;
	
	procedure olahArray(x:nasabah;pos:integer);
	var
		silver,gold,i : integer;
	begin
		writeln;
		silver := 0;
		gold := 0;
		for i := 1 to pos do
			if(x[i].jenisTabungan = 'GOLD') then
				gold := gold +1
			else
				silver := silver+1;
		writeln('Banyaknya Nasabah Gold : ',gold);		
		writeln('Banyaknya Nasabah Silver : ',silver);
		writeln;
	end;
	
	procedure sortingDataNama(var x: nasabah;n:integer);
	var
		i,j:integer;
		tmp : idn;
	begin
		writeln;
		for i:= 2 to n do
		begin
			tmp:= x[i];
			j:= i-1;
			while(j >= 1) and(x[j].nama > tmp.nama) do
			begin
				x[j+1]:=x[j];
				j:=j-1;
			end;
			x[j+1]:=tmp;
		end;
		writeln;
	end;
	
	procedure delete(var x: nasabah; pos: integer);
	begin
		x[pos].nama := '';
		x[pos].jenisTabungan:= '';
		x[pos].jumlahSetoranAwal:=0;
		x[pos].biayaAdminBulanan := 0;
		x[pos].biayaPenarikanlain := 0;
	end;
	
	procedure sortingDataSetoran(var x: nasabah;n:integer);
	var
		i,j:integer;
		tmp : idn;
	begin
		writeln;
		for i:= 2 to n do
		begin
			tmp:= x[i];
			j:= i-1;
			while(j >= 1) and(x[j].jumlahSetoranAwal < tmp.jumlahSetoranAwal) do
			begin
				x[j+1]:=x[j];
				j:=j-1;
			end;
			x[j+1]:=tmp;
		end;
		writeln;
	end;
	
	procedure outputSemua(x: nasabah; awal,pos : integer);
	var
		i : integer;
	begin
		writeln;
		for i := awal to pos do
			if(x[i].nama <>'') then
			begin
				writeln('Id : ',x[i].id);
				writeln('Nama : ',x[i].nama);
				writeln('Jenis Tabungan : ',x[i].jenisTabungan);
				writeln('Setoran awal : ',x[i].jumlahSetoranAwal);
				writeln('Biaya admin bulanan : ',x[i].biayaAdminBulanan);
				writeln('Biaya penarikan di atm lain : ',x[i].biayaPenarikanlain);
				writeln;
			end;
		writeln;
	end;
	
	function cariNama(x: nasabah; pos : integer;y:string):integer;
	var
		i: integer;
	begin
		i:=1;
		while(i < pos) and (i <nMax) and (x[i].nama <> y) do
			i:= i+1;
		if (x[i].nama = y) then
			cariNama:= i
		else
			cariNama:=-1;
	end;
	
	procedure isiData(var x: nasabah;var pos,y: integer);
	var
		n,i: integer;
	begin
		writeln;
		write('Jumlah data : ');
		readln(n);
		i:=0;
		while(i< n) and (pos < nMax)  do
		begin
			writeln;
			pos := pos+1;
			x[pos].id:= y;
			inputNama(x[pos].nama);
			inputJenisSetoran(x[pos].jenisTabungan,x[pos].jumlahSetoranAwal);
			olahData(x,pos);
			i := i+1;
			y := y+1;
		end;
		writeln;
	end;
	
	procedure sortingData(var x: nasabah; pos : integer);
	var
		i : integer;
	begin
		repeat
			writeln('Menu Sorting Data');
			writeln('1. Sorting Nama');
			writeln('2. Sorting setoran');
			writeln('3. Menu utama');
			pilihan(i);
			if(i = 1) then
			begin
				sortingDataNama(x,pos);
				writeln('Data telah Terurut dari A ke Z');
			end;
			if(i = 2) then
			begin
				sortingDataSetoran(x,pos);
				writeln('Data telah Terurut dari terbesar');
			end;
			writeln;
		until(i = 3);
	end;
	
	procedure cariData(x: nasabah; pos : integer);
	var
		y,z:string;
		i: integer;
	begin
		writeln;
		write('Nama yang ingin dicari : ');
		readln(y);
		i:= cariNama(x,pos,y);
		if(i <> -1) then
		begin
			writeln('Nama yang dicari ditemukan');
			write('Tampilkan semua datanya ? (ya/tidak) ');
			readln(z);
			if(z ='ya') then
				outputSemua(x,i,i);
		end else
			writeln('Nama tak ditemukan ');
		writeln;
	end;
	
	procedure editData(var x: nasabah; var pos : integer);
	var
		a,y,cek:string;
		i,z:integer;
	begin
		repeat
			writeln;
			write('Nama yang ingin diedit / didelete : ');
			readln(y);
			i:= cariNama(x,pos,y);
			if(i <> -1) then
			begin
				outputSemua(x,i,i);
				write('delete / edit ? ');
				readln(a);
				if(a ='edit') then
				begin
					repeat
						writeln('1. Nama');
						writeln('2. Jenis tabungan dan jumlah setoran awal ');
						writeln('3. Selesai');
						write('Data yang  diedit? ');
						readln(z);
						if(z = 1) then
							inputNama(x[i].nama);
						if(z = 2) then 
							inputJenisSetoran(x[i].jenisTabungan,x[i].jumlahSetoranAwal);
						olahData(x,i);
					until (z = 3);
				end;
				if(a = 'delete') then
				begin
					delete(x,i);
					writeln('data teleh didelete');
					sortingDataSetoran(x,pos);
					pos:=pos-1;
				end;
			end else
				writeln('Nama tak ditemukan');
			repeat
				write('ingin mencari lagi? (ya/tidak) ');
				readln(cek);
			until((cek ='ya') or (cek ='tidak'));
		until(cek = 'tidak');
		writeln;
	end;
	
	procedure outputData(x: nasabah; pos : integer);
	var
		i:integer;
	begin
		writeln;
		repeat
			writeln('1. Semua data');
			writeln('2. Banyaknya nasabah perjenis tabungan');
			writeln('3. Menu utama');
			pilihan(i);
			if(i = 1) then
				outputSemua(x, 1,pos);
			if(i = 2) then
				olahArray(x,pos);
		until(i = 3);
		writeln;
	end;

begin
	n:=0;
	num := 1234;
	repeat
	tampilan;
	pilihan(i);
	case i of
		1 : isiData(bank,n,num);
		2 : cariData(bank,n);
		3 : sortingData(bank,n);
		4 : editData(bank,n);
		5 :	outputData(bank,n);
	end;
	until (i = 6);
	writeln('Terima Kasih');
end.