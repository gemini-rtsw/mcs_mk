%define debug_package %{nil}
%define _build_id_links none
%define name mcs_mk
%define version 1.0.0
%define repository gemdev
%define _prefix /gem_base/epics/ioc
%define arch %(uname -m)
%define checkout %(git log --pretty=format:'%h' -n 1) 

%global _enable_debug_package 0
%global debug_package %{nil}
%global __os_install_post /usr/lib/rpm/brp-compress %{nil}

Summary: %{name} Package
Name: %{name}
Version: %{version}
Release: 8.git%{git_hash}%{?dist}
License: EPICS Open License
Group: Applications/Engineering
Source0: %{name}-%{version}.tar.gz
ExclusiveArch: %{arch}
Prefix: %{_prefix}
## You may specify dependencies here
BuildRequires: epics-base-devel re2c tdct sequencer-devel autosave-devel bancomm-devel geminiRec-devel timelib-devel pmaclib-devel slalib-devel xycom-devel gemUtil-devel timeProbe-devel pvload-devel
Requires: epics-base sequencer autosave bancomm geminiRec timelib pmaclib slalib xycom gemUtil timeProbe pvload
## Switch dependency checking off
AutoReqProv: no

%description
This is the module %{name}.

## If you want to have a devel-package to be generated uncomment the following:
%package devel
Summary: %{name}-devel Package
Group: Development/Gemini
Requires: %{name} tdct sequencer-devel autosave-devel  bancomm-devel geminiRec-devel timelib-devel pmaclib-devel slalib-devel xycom-devel gemUtil-devel timeProbe-devel pvload-devel
%description devel
This is the module %{name}.

%prep
%setup -q 

%build
#update environment from former rpm installations due to BuildRequires
source /gem_base/etc/profile
#start virtual framebuffer to have graphics for java
#Xvfb :1  -ac -nolisten tcp -nolisten unix &

make distclean uninstall
#DISPLAY=:1 make
make
#killall Xvfb

%install
export DONT_STRIP=1
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r dbd $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r db $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r bin $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r include $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r configure $RPM_BUILD_ROOT/%{_prefix}/%{name}


%postun
if [ "$1" = "0" ]; then
	rm -rf %{_prefix}/%{name}
fi


%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
   /%{_prefix}/%{name}/bin
   /%{_prefix}/%{name}/db
   /%{_prefix}/%{name}/dbd
   /%{_prefix}/%{name}/include
   /%{_prefix}/%{name}/configure


%files devel
%defattr(-,root,root)
   /%{_prefix}/%{name}/db
   /%{_prefix}/%{name}/dbd
   /%{_prefix}/%{name}/include
   /%{_prefix}/%{name}/configure

%changelog
* Mon Jun 13 2022 Cristian Urrutia <cristian.urrutia@noirlab.edu> 
- new package built with tito

