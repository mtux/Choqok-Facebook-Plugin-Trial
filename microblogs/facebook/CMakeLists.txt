find_package(KFacebook)

IF(KFacebook_FOUND)
    message(STATUS "FOUND KFacebook: Will build Facebook plugin")
    include_directories(
    ${CHOQOK_INCLUDES}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${KFACEBOOK_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    )

    set( choqok_facebook_SRCS
    facebookaccount.cpp
    facebookmicroblog.cpp
    facebookeditaccountwidget.cpp
    facebookpostwidget.cpp
    )

    kde4_add_ui_files(choqok_facebook_SRCS
    facebookeditaccount_base.ui
    )

    kde4_add_plugin(choqok_facebook ${choqok_facebook_SRCS})

    target_link_libraries(choqok_facebook ${KDE4_KDECORE_LIBS}   ${KDE4_KDEUI_LIBS}   ${QT_QTGUI_LIBRARY}   ${QT_QTWEBKIT_LIBRARY}   ${KDE4_KDEWEBKIT_LIBS}   ${KDE4_KIO_LIBS}   ${QJSON_LIBRARIES}   ${QJSON_LIBRARY}   ${KDEPIMLIBS_KABC_LIBS}   ${KDEPIMLIBS_KPIMUTILS_LIBS}   ${KDEPIMLIBS_KMIME_LIBS} ${KFACEBOOK_LIBRARIES} choqok )
    #target_link_libraries(choqok_facebook ${KDE4_KDEUI_LIBS} ${LIBKFACEBOOK_LIBRARIES} choqok)

    # Install


    install(TARGETS choqok_facebook DESTINATION ${PLUGIN_INSTALL_DIR})
    install( FILES choqok_facebook.desktop  DESTINATION ${SERVICES_INSTALL_DIR})

    add_subdirectory(icons)

ELSE(KFacebook_FOUND)
    message(WARNING "KFacebook NOT FOUND, won't build Facebook plugin")
ENDIF(KFacebook_FOUND)




