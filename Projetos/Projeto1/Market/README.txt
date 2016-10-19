    ### Manual de Operação para o Simulador de Supermercados ###

    Ao iniciar a execução, será questionado qual o método de obtenção de parâmetros
    será utilizado.

    * Pressione 1 seguido de Enter para selecionar a entrada de parâmetros com arquivo.
    Para mais informações, leia a Seção I.

    ou

    * Pressione 2 seguido de Enter para selecionar a entrada de parâmetros manual.
    Para mais informações, leia a Seção II.

    ============================================================================

    # Seção I - "Entrada de parâmetros por arquivo"

    * Junto com os arquivos .c e .cpp, haverá um arquivo nomeado como "input.dat".
    Nele estarão os parâmetros que alimentarão o simulador.
    * Frases iniciadas com '#' são consideradas como comentários, portanto serão
    ignoradas.
    * A primeira linha conterá o nome do supermercado.
    * A segunda linha conterá o tempo de simulação desejado.
    * A terceira linha conterá o tempo médio de chegada de cada cliente.
    * Por fim, a quarta linha conterá o número de caixas que o mercado terá.

    * Nas linhas seguintes, conterão os atributos de cada caixa do mercado,
    sendo 1 caixa por linha.
    * A primeira palavra será seu identificador, seguido de 'espaço' e seu
    desempenho (1, 2 ou 3), seguido de 'espaço' e seu salário.

    ============================================================================

    # Seção II - "Entrada de parâmetros manual"

    * Informe o nome do supermercado. (Obs.: O nome não deve conter espaços,
    caso necessário, separe os nomes com um "_").
    * Insira o tempo de simulação desejado (um inteiro positivo).
    * Insira o tempo médio de chegada de cda cliente (um inteiro positivo).
    * Insira o número de caixas do supermercado (um inteiro positivo).

    * Informe o identificador do caixa (pode ser o nome ou um número).
    * Informe o desempenho do caixa. (Obs.: O número deve ser 1, 2 ou 3).
    * Informe o salário do caixa (um double).
    * Repita estes 3 passos até adicionar todos os caixas.

    ============================================================================

    Após o último passo, a simulação iniciará e todas as informações referentes
    a ela estarão disponíveis no console.
