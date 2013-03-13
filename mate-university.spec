Name:           mate-university
Summary:        MATE University
Version:        1.5.0
Release:        1%{?dist}
License:	GPLv3+
URL:		http://mate-desktop.org
Source0:	mate-university-1.5.0.tar.gz

BuildRequires:	mate-common
BuildRequires:  mate-panel-devel

%description
MATE University

%prep
%setup -q
NOCONFIGURE=1 ./autogen.sh

%build
%configure
make %{?_smp_mflags} V=1


%install
make install DESTDIR=%{buildroot}


%files
%{_libexecdir}/university-applet
%{_libexecdir}/university-python-applet
%{_datadir}/dbus-1/services/org.mate.panel.applet.UniversityAppletFactory.service
%{_datadir}/dbus-1/services/org.mate.panel.applet.UniversityPythonAppletFactory.service
%{_datadir}/locale/it/LC_MESSAGES/mate-university.mo
%{_datadir}/mate-panel/applets/org.mate.university.Applet.mate-panel-applet
%{_datadir}/mate-panel/applets/org.mate.university.PythonApplet.mate-panel-applet

%changelog
* Wed Mar 13 2013 - Dan Mashal <dan.mashal@fedoraproject.org> - 1.5.0-1
-Initial build
