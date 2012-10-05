times = unique(moutput(:,3));

fps = 33;

%screen_size = get(0, 'ScreenSize');
fig1 = figure(1);
%set(fig1, 'Position', [0 0 screen_size(3)/2 screen_size(4)/4 ] );

numframes = fix(max(times)*fps)-1;

clf;
hold on;

winsize = get(fig1,'Position');
winsize(1:2) = [0 0];

A = moviein(numframes,fig1,winsize);

set(fig1,'NextPlot','replacechildren');



n = 8;

for i=1:numframes
	ind = find(times>(i/fps));
	time = times(ind(1));
	inds = find(moutput(:,3) == time);
	clf;

	plot(moutput(inds,1),moutput(inds,2), '.')
	axis([0 1 0 1]);

	title('/Fake/ Water Simulation');

	A(:,i) = getframe(fig1,winsize);
	disp('Finished Frame');
end

save filename.mat A

movie2avi(A,'testing.avi','FPS',fps);
